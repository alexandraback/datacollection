x = open("bin.txt","r")
t = int(x.readline())
with open("bout.txt","w") as fout:
    for i in range(1,t+1):
        n = int(x.readline())
        cache = [1000000]*(n+1)
        cache[1] = 1
        for j in range(1,n):
            cache[j + 1] = min(cache[j + 1], cache[j] + 1)
            tmp = list(str(j))
            tmp.reverse()
            tmp = int(''.join(tmp))
            if(tmp > j and tmp < n+1):
                cache[tmp] = min(cache[tmp], cache[j] + 1)
        fout.write("Case #" + str(i) + ": " + str(cache[n]) + "\n")
x.close()
