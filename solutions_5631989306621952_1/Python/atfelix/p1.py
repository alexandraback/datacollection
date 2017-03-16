def greedy(s):
    answer = s[0]
    s = s[1:]
    while s:
        if s[0] >= answer[0]:
            answer = s[0] + answer
        else:
            answer += s[0]
        s = s[1:]
    return answer

def main():
    for _ in range(int(input())):
        print('Case #%d: %s' % (_ + 1, greedy(input())))

if __name__ == '__main__':
    main()
