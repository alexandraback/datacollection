DEBUG = False


def main():
    #for i in range(2, 7):
    #    print(i, max_ways(i))
    with open('test.out', 'w') as g:
        with open('test.in') as f:
            T = int(f.readline())
            for t in range(T):
                B, M = map(int, f.readline().strip().split())
                answer_str = 'Case #{}: '.format(t + 1) + str(answer(B, M))
                print(answer_str)
                g.write(answer_str)
                g.write('\n')


def answer(B, M):
    if M <= max_ways(B):
        tbremoved = max_ways(B) - M
        tbremoved = "{0:b}".format(tbremoved)
        if DEBUG:
            print(max_ways(B))
            print(M)
            print(tbremoved)
        slides = []
        for origin in range(B):
            bslides = []
            for target in range(B):
                if target > origin:
                    bslides.append('1')
                else:
                    bslides.append('0')
            slides.append(bslides)
        for i, digit in enumerate(leftpad(tbremoved, B)):
            if digit == '1':
                slides[0][i - 1] = '0'
        return "POSSIBLE" + '\n' + '\n'.join(map(rep, slides))
    return "IMPOSSIBLE"


def leftpad(s, n):
    while len(s) < n:
        s = '0' + s
    return s


def rep(slides):
    return ''.join(slides)

def max_ways(B):
    return 2 ** (B - 2)


if __name__ == '__main__':
    main()