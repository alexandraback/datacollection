new=open("D-large.in")

new1=open("output.txt","w")
n1=new.readline()
for i in range(int(n1)):
   
    a=new.readline()
    [a1,a2,a3]=[int(i) for i in a.split()]
    win=False
    if a1>=7:
        new1.write('Case #'+str(i+1)+': '+'RICHARD'+'\n')
        win=True
    elif a1>a2 and a1>a3:
        new1.write('Case #'+str(i+1)+': '+'RICHARD'+'\n')
        win=True
    elif (a2*a3) % a1 !=0:
        win=True
        new1.write('Case #'+str(i+1)+': '+'RICHARD'+'\n')
    else:
        num=min(a2,a3)
        if num<int((a1+1)/2):
            new1.write('Case #'+str(i+1)+': '+'RICHARD'+'\n')
            win=True
        elif num==int((a1+1)/2):
            if a1>=4:
                new1.write('Case #'+str(i+1)+': '+'RICHARD'+'\n')
                win=True
    if win==False:
        new1.write('Case #'+str(i+1)+': '+'GABRIEL'+'\n')
    

        
     

