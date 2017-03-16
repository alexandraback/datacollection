def solve(s1, s2):
    n = len(s1)
    digits1, digits2 = [x for x in s1], [x for x in s2]
    less = False
    for i in range(n):
        if digits1[i] == '?' and digits2[i] == '?':
            if less:
                digits1[i] = '9'
                digits2[i] = '0'
            else:
                digits1[i] = '0'
                digits2[i] = '0'
        elif digits1[i] == '?':
            digits1[i] = digits2[i]
        elif digits2[i] == '?':
            digits2[i] = digits1[i]
        else:
            less = True
    coders, jammers = int(''.join(digits1)), int(''.join(digits2))
    return '%d %d' % (coders, jammers)

def main():
    for _ in range(int(input())):
        print('Case #%d: %s' % (_ + 1, solve(*input().split())))

if __name__ == '__main__':
    main()
