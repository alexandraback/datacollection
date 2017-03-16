T = int(input())
test = 1

while test <= T:
    print("Case #" + str(test) + ": ", end="")
    test += 1
    pq = input().split('/')
    p = int(pq[0])
    q = int(pq[1])
    rem = p / q
    done = False
    ans = 0
    for i in range(1, 41):
        qty = rem // (1/2**i)
        rem -= (1/2**i)*qty
        if qty > 0 and ans == 0:
            ans = i
        if rem <= 0:
            done = rem == 0
            break
    if done:
        print(ans)
    else:
        print("impossible")