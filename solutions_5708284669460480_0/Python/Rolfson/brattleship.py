import math

fin = open('input.in', 'r')
output = open('output.txt','w')

loops = int(fin.readline())

for x in range(loops):
    notfound = True
    k,l,s = fin.readline().split()
    k = int(k)
    l = int(l)
    s = int(s)
    chance = 1
    keyboard = fin.readline().rstrip()
    target= fin.readline().rstrip()
    setofletters = ''.join(set(target))
    for letter in target:
        if letter in setofletters:
            countTarget = target.count(letter)
            #print("Count of " + letter + " in target is: " + str(countTarget))
            countKeyboard = keyboard.count(letter)
            #print("Count of " + letter + " in keyboard is: " + str(countKeyboard))
            chance = chance * math.pow(float(countKeyboard / len(keyboard)), countTarget)
            #print("Chance of typing letter is " + str(chance))
            setofletters = setofletters.replace(letter,'')
            if countKeyboard == 0:
                notfound = False
    outputstr = "Case #" + str(x+1) + ": "
    #outputstr = "Case #" + keyboard + ": " 
    if(notfound == True):
        possibilities = s / len(target)
        outputpercent = round(math.ceil(possibilities) * chance, 7)
        possibilities = math.floor(possibilities)
        final = round(possibilities - outputpercent, 7)
        if final< 0:
            final = 0.0
        output.write(outputstr + str(final) + "\n")
    else:
        output.write(outputstr + "0.0\n")
        
    
    
    #if w != r*c:
        #output.write("Case #" +str(x + 1)+ ": " + str(math.ceil(c/w) * r + (w - 1)) + "\n")
    #else:
        #output.write("Case #" + str(x+1) + ": " + str(w) + "\n")

output.close()
        
