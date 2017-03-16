t = int(input())

def normalGame(naomi, ken):
    scoreNormal = 0

    naomi = list(naomi)
    ken = list(ken)
    
    #Naomi plays her smallest weight
    #Ken will play the smallest weight greater than naomis, or if he doesn't have
    # a greater weight, he will play his smallest one
    while naomi:
        s = naomi[0]
        found = False
        for x in ken:
            if x > s:
                found = True
                break
        naomi = naomi[1:]
        if found:
            ken.remove(x)
        else:
            ken = ken[1:]
            scoreNormal += 1
    return scoreNormal

def deceitful(naomi, ken):
    scoreDeceitful = 0   

    naomi = list(naomi)
    ken = list(ken)
    
    #Use smallest elements to waste his big ones
    while ken:
        if ken[-1] > naomi[-1]:
            ken = ken[:-1]
            naomi = naomi[1:]
        else:
            break

    #If naomi's smallest is greated than ken's smallest, she wont be able to get a element with that,
    # but she can use it to take ken's big one
    while ken:
        if naomi[0] < ken[0]:
            naomi = naomi[1:]
            ken = ken[:-1]
        else: break

    while naomi:
        if naomi[-1] > ken[-1]:
            naomi = naomi[:-1]
            ken = ken[:-1]
            scoreDeceitful += 1
        else:
            naomi = naomi[1:]
            ken = ken[:-1]
    
    return scoreDeceitful

for i in range(t):
    blocks = int(input())
    naomi = list(sorted(map(float, input().split()))) 
    ken = list(sorted(map(float, input().split()))) 

    print ("Case #{}: {} {}".format(i + 1, deceitful(naomi, ken), max(
        normalGame(naomi, ken), normalGame(reversed(naomi), ken))))

    #print (naomi, ken)
