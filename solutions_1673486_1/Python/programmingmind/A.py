f = open('A-large.in','r')

a = f.read()
f.close()
b = a.split('\n')

cases = (int)(b[0])


    

g = open('A.out','w')

current = 1

for i in range(0,cases):
    t = b[current].split(' ')

    num_letters = (int)(t[1])
    num_entered = (int)(t[0])
    current+=1
    t = b[current].split(' ')
    total_prob = []
    prob = []
    tmp = 1
    for j in range(0,num_entered):
        prob.append((float)(t[j]))
        tmp*=(float)(t[j])
        total_prob.append(tmp)
    current+=1
    
    probs = []

    probs.append(2+num_letters) #pressing enter
    probs.append(num_entered+num_letters+1) # backspace everything

    for j in range(0,num_entered):
        p = total_prob[len(total_prob)-(1+j)]
        tmp = p*(num_letters+1+2*j-num_entered) + (1-p)*(2*num_letters+2+2*j-num_entered)
        probs.append(tmp)

    g.write("Case #"+(str)(i+1)+": "+(str)(min(probs))+"\n")

g.close()

