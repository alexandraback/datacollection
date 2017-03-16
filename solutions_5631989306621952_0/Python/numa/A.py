def solve(s):
    ret = s[0];
    for i in range(len(s)):
        if i == 0: 
            continue
        if s[i] < ret[0]:
            ret = ret + s[i]
        else:
            ret = s[i] + ret
    return ret


if __name__ == '__main__':
    n = input()
    for i in range(n):
        x = raw_input()
        ans = solve(x)
        print "Case #" + str(i + 1) + ": " + ans
