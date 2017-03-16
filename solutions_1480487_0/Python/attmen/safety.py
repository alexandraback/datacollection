def auditory(line):
    s = line.split()
    n_cont = int(s[0])
    X = 0
    cont = []
    for i in range(1,n_cont+1):
        cont.append(int(s[i]))
        X += int(s[i])
        
    print n_cont, cont, X        


    if (X != 0):
        for i in range(n_cont):
            cont[i] = float(cont[i]) / float(X)

           

    avg = 2.0 / float(n_cont)
    output = []

    n_under_question = 0
    X_new = 0

    for i in range(n_cont):
        if ((avg - float(cont[i]) ) > 0):
            n_under_question += 1
            X_new += cont[i] 

    avg_new = (1.0 + X_new) / float(n_under_question)

    for i in range(n_cont):
        if (X == 0):
            output.append(1.0 / float(n_cont))
        else:
              if (avg - float(cont[i]) ) > 0:
                  if (X_new > 0):
                      output.append((avg_new - float(cont[i])))
                  else:
                      output.append(1.0 / float(n_under_question))
              else:
                output.append(0.0)
    print avg_new, X_new, output

    return output



       

f = open('C:\\A-small-attempt3.in')
f_out = open('C:\\res.txt','r+')
j = 0
n = 0
for line in f:
    if (j == 0):
        n = int(line)
        j = j + 1
        continue

    out = auditory(line)
    str_out = ''
    for k in range(len(out)):
        str_out += str(out[k] * 100.0)+' '
    f_out.write("Case #"+str(j)+": "+str_out+'\n')
##    out = auditory(line)
##    print out
    j = j + 1
    print j

f.close()
f_out.close()
