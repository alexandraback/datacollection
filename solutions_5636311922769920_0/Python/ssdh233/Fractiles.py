# when input is too large
#f = open("txt","r")
#def input():
#   return f.readline().strip()

def cal(K,C,S):
    if C*S<K:
        return " IMPOSSIBLE"
    else:
        M = int(K/C)
        output = ""
        for i in range(M):
            base = 1 + i * C
            check = base
            for j in range(1,C):
                check = check + (j+base-1) * K**j
            output = output + " " + str(check)
        if int(K/C)*C < K:
            base = int(K/C)*C+1
            check = base
            for j in range(1,K-int(K/C)*C):
                check = check + (j+base-1) * K**j
            output = output + " " + str(check)
        return output







T = int(input())
O = []

for index in range(T):
    K,C,S = map(int, input().split())
    O.append("Case #"+str(index+1)+":"+str(cal(K,C,S)))

for o in O:
    print(o)

