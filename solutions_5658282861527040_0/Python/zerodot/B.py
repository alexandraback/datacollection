
def wins(e):
    count=0
    for i in range(e[0]):
        for j in range(e[1]):
           if i&j<e[2]:
               count=count+1
    return count

if __name__=="__main__":
    cases=int(input())
    for i in range(1,cases+1):
        vals=[int(e) for e in input().split()]
        ans=wins(vals)
        print("Case #"+str(i)+": "+str(ans))
