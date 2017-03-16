def main():
    num_of_tests = int(raw_input())
    for test_i in range(num_of_tests):
        s, n = raw_input().split(' ')
        n = int(n)
        L = len(s)
        ans = 0
        x = 0
        k = 0
        b = [False for i in range(300)]
        b[ord('a')] = b[ord('e')] = b[ord('i')] = b[ord('o')] = b[ord('u')] = True
        b = [b[ord(s[i])] for i in range(L)]
        a = []
        for i in range(L):
            if b[i]:
                k = 0
            else:
                k += 1
                if k > n: k = n
            if k >= n:
                a.append(i)
        ans = 0
        for i in range(len(a)):
            left = max(0, a[i-1] - n + 2) if i > 0 else 0
            ans += (a[i] - n + 1 - left + 1) * (L - 1 - a[i] + 1)
        print "Case #%d: %s" % (test_i + 1, ans)

if __name__ == "__main__":
    main()
