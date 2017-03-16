# when input is too large
#f = open("txt","r")
#def input():
#   return f.readline().strip()

def cal(S):
    count = 0
    for i in range(len(S)):
        if S[i] == "-":
            if i+1 >= len(S):
                count += 1
            elif S[i+1] == "+":
                count += 1
    count = count * 2
    if S[0] == "-":
        count = count - 1
    return count

T = int(input())
O = []

for index in range(T):
    S = input()
    O.append("Case #"+str(index+1)+": "+str(cal(S)))

for o in O:
    print(o)

