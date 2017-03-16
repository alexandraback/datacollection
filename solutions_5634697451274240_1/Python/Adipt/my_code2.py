c = int(raw_input().strip())
i = 0
while c>0:
    c-=1
    i+=1
    n = raw_input().strip()
    buff = '='
    flips = -1
    for j in n:
        if buff!=j:
            buff=j
            flips+=1
    if buff=='-':
        flips+=1
    print "Case #%d:" %(i), flips
