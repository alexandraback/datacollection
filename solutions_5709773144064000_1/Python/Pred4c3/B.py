T=int(input())
for case_id in range(1,T+1):
    C,F,X = map(float,input().split())
    speed,cookie,time = 2.0,0.0,0.0
    while True:
        build_time = C / speed
        end_time = X / speed
        build_end_time = build_time + (X / (speed+F))
        if build_end_time < end_time:
            time += build_time
            speed += F
        else:
            ans = time + end_time
            break
    
    print('Case #%d: %0.7f' % (case_id, ans))
    import sys
    print('Case #%d: %0.7f' % (case_id, ans), file=sys.stderr)
