T=int(input())
for case_id in range(1,T+1):
    D = int(input())
    arr = list(map(int,input().split()))

    def get_special(ma):
        return sum(a//ma-1 if a%ma==0 else a//ma for a in arr if a > ma)

    ans = min(ma + get_special(ma) for ma in range(1,max(arr)+1))            

    print('Case #%d: %d' % (case_id, ans))
    import sys
    print('Case #%d: %d' % (case_id, ans), file=sys.stderr)
