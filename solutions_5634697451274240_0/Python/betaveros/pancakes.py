for i in range(int(input())):s=input()+"+";print("Case #%d: %d"%(i+1,sum(a!=b for a,b in zip(s,s[1:]))))
