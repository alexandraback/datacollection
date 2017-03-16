T = int(input())
test = 1

while test <= T:
    print("Case #" + str(test) + ": ", end="")
    test += 1
    pq = input().split('/')
    p = int(pq[0])
    q = int(pq[1])
    rem = p / q
    if 2**40 * p % q != 0:
        print("impossible")
        continue
    for i in range(1, 41):
        qty = rem // (1/2**i)
        rem -= (1/2**i)*qty
        if qty > 0:
            print(i)
            break