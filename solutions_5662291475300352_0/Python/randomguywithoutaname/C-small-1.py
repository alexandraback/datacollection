def sptime(h):
    return (360.-h[0])*h[1]/360.

def enctime(h1, h2):
    result = (h1[0] - h2[0])*1.0/((h2[1] - h1[1])/360.)
    if result <= 0:
        result = 99999
    r2 = (h1[0] - h2[0] + 360)*1.0/((h2[1] - h1[1])/360.)
    r3 = (h1[0] - h2[0] - 360)*1.0/((h2[1] - h1[1])/360.)
#    print("rates:")
#    print(result)
#    print(r2)
#    print(r3)
    if result == 99999:
        if r2 > 0:
            result = r2
        if r3 > 0:
            result = min(result, r3)
    else:
        if r2 > 0:
            result = min(result, r2)
        if r3 > 0:
            result = min(result, r3)
    return result

T = int(input())
for I in range(1, T+1):
    N = int(input())
    H = []
    for i in range(0, N):
        hikers = tuple(int(k) for k in raw_input().split())
        if hikers[1] == 1:
            H.append(tuple((hikers[0], hikers[2])))
        else:
            for k in range(0, hikers[1]):
                H.append(tuple((hikers[0], hikers[2]+k)))

    H.sort()

    if (len(H) == 1):
        print("Case #%d: %d" % (I, 0))
        continue

    H1 = H[0]
    H2 = H[1]

    et = enctime(H1, H2)
    h1t = H1[0] + et*H1[1]/360.0
    while h1t > 360:
        h1t -= 360
    h2t = H2[0] + et*H2[1]/360.0
    while h2t > 360:
        h2t -= 360

#    print(sptime(H2))
#    print(sptime(H1))
#    print(h1t)
#    print(h2t)

    et2 = enctime(tuple((h1t, H1[1])), tuple((h2t, H2[1])))
#    print(et)
#    print(et2)

    if sptime(H2) < et or et + et2 > sptime(H2):
        result = 0
    else:
        result = 1

    print("Case #%d: %d" % (I, result))
    
