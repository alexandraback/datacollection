#def converter(string):
#    opstring=''
#    for i in string:
#        if i=='+':
#            opstring=opstring+'1'
#        else:
#            opstring=opstring+'0'
#    return opstring

def solver(string,op):    
    q=set(string)
    if len(q)==1:
        if q==set(op):
            return 0
        else:
            return 1
    else:
        temp=solver(string[:-1],string[-1])
        if string[-1]==op:
            return temp
        else:
            return temp+1
    
t=input()
l=[]
for i in range(t):
    l.append(raw_input())
for i in range(len(l)):
#    x=converter(l[i])
    print 'Case #'+str(i+1)+': '+str(solver(l[i],'+'))
    
