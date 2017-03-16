

def bff(kids):
    ans = 0
    terminal = [0]*len(kids)
    ##check for terminal nodes
    for k in range(0, len(kids)):
        pt = kids[k]
        if k == kids[pt]:
            term1 = pt
            term2 = k
            ans1 = 0
            ans2 = 0
            for i in range(0, len(kids)):
                counter = 0
                pt = kids[i]
                for j in range(0,len(kids)+2):
                    if i != term2 and pt != term2:
                        counter += 1
                        if pt == term1:
                            ans1 = max(ans1,counter + 1)
                            counter = 0
                        pt = kids[pt]
                

            for i in range(0, len(kids)):
                counter = 0
                pt = kids[i]
                for j in range(0,len(kids)+2):
                    if(pt != term1 and i != term1):
                        counter += 1
                        if pt == term2 and pt != term1:
                            ans2 = max(ans2,counter+1)
                            counter = 1
                        pt = kids[pt]
                
           
            ans = max(ans,max(ans1,1)+max(ans2,1))
    
    for i in range(0, len(kids)):
        counter = 0
        pt = kids[i]
        for j in range(0,len(kids)+2):
            counter += 1
            if i == pt:
                #print("Debug", pt, counter)
                ans = max(ans,counter)
                counter = 0
            pt = kids[pt]
    return ans

def main():
    length = int(input())
    ans = []
    for i in range(0,length):
        number = int(input())
        kids = input().split()
        for j in range(0,number):
            kids[j] = int(kids[j]) - 1
        ans += [bff(kids)]

    for i in range(0,len(ans)):
        print("Case #" + str(i+1) + ": " + str(ans[i]))
