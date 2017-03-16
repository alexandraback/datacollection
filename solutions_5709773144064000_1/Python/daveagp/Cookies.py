input = open("B-large.in")

cases = int(input.readline())

for case in range(1, cases+1):
    c, f, x = (float(x) for x in input.readline().split(" "))
        
    k = 0
    buildup = 0 # time to buy k farms
    overall = x/2 # time to win if buying k farms
    
    while True:
        k += 1
        newbuildup = buildup + c/(2 + (k-1)*f)
        newoverall = newbuildup + x/(2+k*f)
        if newoverall > overall: break
        buildup, overall = newbuildup, newoverall

    print("Case #"+str(case)+": "+str(overall))
