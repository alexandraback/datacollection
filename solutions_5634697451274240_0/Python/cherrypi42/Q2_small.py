def flippityflip(stack, cake): #cake = number of bottom cake to flip; first cake is 0
    store = stack[0 : cake + 1]
    for i in range(cake + 1):
        if store[i] == '-':
            stack[cake - i] = '+'
        else:
            stack[cake - i] = '-'
            
#a=['-', '+', '+', '-']
#flippityflip(a,2)
#print a           

fileout = open('small.out',"w")
happy = set("+")
mixedfeelings = set("+-")

with open('small.in') as file:
    T = int(file.readline())
    
    for case in range(1, T+1):
        stack = list(file.readline().strip())
        flips = 0
        while set(stack) == mixedfeelings:
            j = 0
            while ((j < len(stack) - 1) & (stack[j] == stack[j + 1])):
                j += 1
            flippityflip(stack, j)
            flips += 1
        if set(stack) != happy:
            flips += 1
        fileout.write("Case #" + str(case) + ": " + str(flips) + "\n")
        
fileout.close()
