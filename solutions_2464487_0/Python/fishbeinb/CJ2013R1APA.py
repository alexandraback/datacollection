#Code Jam 2013 - R1A - PA
#Ben Fishbein
#4/13
#Bullseye
#Find how large of a bullseye I can make
#https://code.google.com/codejam/contest/2418487/dashboard#s=p0

from math import *
into = open('CJ2013R1APA.in')
out = open('CJ2013R1APA.out', 'w')

lines = []
lines = into.readlines()

for y in range(int(lines[0])):
    a = lines[y+1].split()
    r = int(a[0])
    t = int(a[1])
    print r, t
    #rings = 0
    #add = 1
    top = 1
    bot = 1
    x = 0
    truth = True
    end = True
    while(truth):
        if(t >= top*2*r + 4*top*(top - 1)/2 + top):
            bot = top
            top = top*2
        else:
            truth = False
    while(end):
        x = int(floor((bot + top)/2))
        if(t >= x*2*r + 4*x*(x - 1)/2 + x):
            bot = x
           # print x, "bot"
        else:
            top = x
            #print x, "top"
        if ((bot+1)>= top):
            end = False
    x = int(ceil((bot + top)/2))  
    #print x, "final"
    out.write("Case #" + str(y + 1) + ": " + str(x)+ "\n")
out.close()


#    fucking not being able to du a fucking simple binary search I'm so stupid
 #   print sqrt(4*r*r-4*r+8*t+1), "sqrt"
  #  print (sqrt(4*r*r-4*r+8*t+1)-2*r+1), "minues"
   # rings = (sqrt(4*r*r-4*r+8*t+1)-2*r+1)/4
    #print int(floor(rings)), "option 1"
        
#    while (t>0):
 #       rings = rings + 1
        #t = t - 2*r - (add*2-1)
  #      add = add + 2
   #     if (t < 0):
    #        rings = rings - 1
     #   print t, "t"
        

#1 + 5 + 9 + 13 .. x= x +  x(x-1)/2
##total = x*2*r + x*(x - 1)/2 + x
## wolfram solve for x t = x*2*r + 4*x*(x - 1)/2 + x
#x = 1/4 (-sqrt(4 r^2-4 r+8 t+1)-2 r+1) or x = 1/4 (sqrt(4 r^2-4 r+8 t+1)-2 r+1)
#floor x








"""
    if (winner == 1):
        out.write("Case #" + str(x + 1) + ": " + "X won\n")
    elif (winner == 2):
        out.write("Case #" + str(x + 1) + ": " + "O won\n")
    else:
        out.write("Case #" + str(x + 1) + ": " + winner5 + "\n")
out.close()
        
"""
