T = int(raw_input())

for t in range(1,T+1):
    stack = raw_input()
    flips = 0
    lastPancake = stack[0]
    for pancake in stack :
        if pancake != lastPancake:
            flips += 1
        lastPancake = pancake
    if lastPancake == "-":
        flips += 1
    print "Case #"+str(t)+": "+str(flips)
