
def ok(s, n):
    k = 0
    for c in s:
        if c in ['a', 'e', 'i', 'o', 'u']:
            k = 0
        else:
            k += 1
        if k >= n:
            return True
    return False

def main():
    num_of_tests = int(raw_input())
    for test_i in range(num_of_tests):
        s, n = raw_input().split(' ')
        n = int(n)
        L = len(s)
        ans = 0
        for i in range(L):
            for j in range(i + n - 1, L):
                if ok(s[i:j + 1], n):
                    ans += 1
        print "Case #%d: %s" % (test_i + 1, ans)

if __name__ == "__main__":
    main()
