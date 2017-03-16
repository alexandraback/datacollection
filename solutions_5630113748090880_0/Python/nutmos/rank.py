T = int(raw_input())
for I in range(1,T+1):
    n = int(raw_input())
    result = []
    for i in range(0,(n<<1)-1):
        s = raw_input().split()
        for j in s:
            intj = int(j)
            if intj in result:
                result.remove(intj)
            else:
                result.append(intj)
    result = sorted(result)
    strresult = ""
    for c in result:
        strresult = strresult + " " + str(c)
    print "Case #" + str(I) + ":" + strresult
