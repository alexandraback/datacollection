T = int(raw_input())  
#n, m = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case

for K in range (T):
    n = int(raw_input())
    first = {}
    second = {}
    name = []
    ans = 0

    for i in range(n):
        a,b = raw_input().split(" ")
        name.append([a,b])

        if a in first:
            first[a] += 1
        else:
            first[a] = 1

        if b in second:
            second[b] += 1
        else:
            second[b] = 1

    for i in range(n):
        a,b = name[i]
        if first[a]>1 and second[b]>1:
            ans += 1




    print ("Case #{}: {}".format(K+1, ans))
    

