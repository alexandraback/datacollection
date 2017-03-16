import math

if __name__ == "__main__":
    
    T = int(input())

    N, J = map(int,input().split())

    ans = []

    strnum =  2**(N-1) + 1

    while(len(ans) < J):
        
        sn = bin(strnum)[2:]
        res = [sn]

        for base in range(2,11):
            bn = int(sn,base)
            limit = math.sqrt(bn)

            Find = False
            
            for div in range(2,int(limit)+1):
                
                if bn % div == 0:
                    #print(bn, div, bn//div)
                    res.append(div)
                    Find = True
                    break

            if Find:
                continue
            else:
                #print("F")
                break

        if len(res) == 10:
            ans.append(res)

        strnum += 2

    print("Case #{}:".format(T))
    for x in ans:
        for y in x:
            print(y,end=' ')
        print()
        
