import itertools
def solve(words):
    ans = 0
    for situation in itertools.product([True, False], repeat=len(words)):
        first = set()
        second = set()
        counter = 0
        OK = True
        for i in range(len(words)):
            if situation[i]:
                first.add(words[i][0])
                second.add(words[i][1])
        for i in range(len(words)):
            if not situation[i]:
                counter += 1
                if words[i][0] not in first or words[i][1] not in second:
                    OK = False
                    break
        if OK and counter > ans:
            ans = counter
    return ans

def main():
    T = input()
    for i in xrange(1, T + 1):
        N = input()
        words = []
        for j in xrange(N):
             words.append(raw_input().split())
        print 'Case #{0}: {1}'.format(i, solve(words))

if __name__ == '__main__':
    main()
