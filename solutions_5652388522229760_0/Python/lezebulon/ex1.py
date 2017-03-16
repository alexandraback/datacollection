def digitsIn(n):
    digits = set()

    for i in range(1,1001):
        n2 = n*i
        l = list(str(n2))
        for s in l:
            digits.add(int(s))

        if len(digits) == 10:
            return n2

    return -1



for tc in range(int(input())):
    n = int(input())
    k =  digitsIn(n)
    if k == -1:
        print("Case #" + str(tc+1) +": INSOMNIA")
    else:
        print("Case #" + str(tc+1) +": " + str(k))
        
