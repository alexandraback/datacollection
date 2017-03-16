def helper(a):
    if a == 0:
        return 'INSOMNIA'
    cur = a
    digits = set()
    while True:
        for c in str(cur):
            digits.add(c)
        if len(digits) == 10:
            break
        cur += a
    return str(cur)


def main():
    n = int(raw_input())
    for i in range(n):
        print "Case #{}: {}".format(i+1, helper(int(raw_input())))

if __name__ == '__main__':
    main()
