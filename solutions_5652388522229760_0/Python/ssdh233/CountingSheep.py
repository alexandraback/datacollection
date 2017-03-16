# when input is too large
#f = open("txt","r")
#def input():
#   return f.readline().strip()

def cal(N):
    if N == 0:
        return "INSOMNIA"
    else:
        num = [False for i in range(10)]
        strN = str(N)
        for i in [int(i) for i in str(N)]:
            if not num[i]:
                num[i] = True
        count = 2
        while not check(num):
            NN = N * count
            count = count + 1
            for i in [int(i) for i in str(NN)]:
                if not num[i]:
                    num[i] = True
        return NN

def check(num):
    for i in range(10):
        if num[i] == False:
            return False
    return True

T = int(input())
O = []

for index in range(T):
    N = int(input())
    O.append("Case #"+str(index+1)+": "+str(cal(N)))

for o in O:
    print(o)

