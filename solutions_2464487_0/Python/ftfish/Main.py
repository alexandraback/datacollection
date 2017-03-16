if __name__ == '__main__':
    Tn = int(raw_input())
    for Tc in xrange(1, Tn + 1):
        r, t = map(int, raw_input().split())
#         for i in range(10):
#             print i * (2 * i + 2 * r - 1)
        
        ans = 1
        left = 1
        right = 2 ** 64
        while left <= right:
            m = (left + right) >> 1
            if m * (2 * m + 2 * r - 1) <= t:
                ans = m
                left = m + 1
            else:
                right = m - 1
        
        print 'Case #%d: ' % Tc,
        print ans
