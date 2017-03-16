c = int(raw_input().strip())
i = 0
while c>0:
    c-=1
    i+=1
    n = int(raw_input().strip())
    r = 0
    a = [0 for j in range(10)]
    if n==0:
        print "Case #%d: INSOMNIA" %i
        continue
    while True:
        if a == [1 for j in range(10)]:
            break
        r+=n
        d = r
        while d!=0:
            a[d%10]=1
            d/=10
    print "Case #%d:" %(i), r
