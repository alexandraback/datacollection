import math, time



t1 = time.time()    
n= 0
finput = open("data.txt","r")
foutput = open("output.txt","w")
testcase = []
for line in finput:
    if line[-1] == "\n":
        dati = line[:-1]
        #dati = line[:-1]
    else:
        dati = line
        #dati = line
    if n == 0:
        T = int(dati)
          
    else:
        if n <= T:
           testcase.append(dati.split())
                
    n +=1


#print (T,testcase)
txt_output = ""

for n in range(T):
    C = testcase[n][0]
    J = testcase[n][1]
    #print (C,J)
    grandezza = len(C)
    min_C = ""
    max_C = ""
    min_J = ""
    max_J = ""
    for x in range(grandezza):
        if C[x] == "?":
            min_C = min_C + "0"
            max_C = max_C + "9" 
        else:
            min_C = min_C + C[x]
            max_C = max_C + C[x]
        if J[x] == "?":
            min_J = min_J + "0"
            max_J = max_J + "9" 
        else:
            min_J = min_J + J[x]
            max_J = max_J + J[x]
    max_C = int(max_C)
    min_C = int(min_C)
    max_J = int(max_J)
    min_J = int(min_J)
    diff = max(abs(max_C-min_J),abs(min_C-max_J))
    #print (min_C,max_C,"----",min_J,max_J,"----",diff,)
    c_temp = min_C
    j_temp = min_J
    for c in range(min_C,max_C+1):
        prova = str(c)
        
        for z in range(len(prova), grandezza):
            prova = "0" + prova
        ok = True
        for z in range(grandezza):
            if C[z] != "?":
                if C[z] != prova[z]:
                    ok = False
        if ok:
            
            trovato = False
            for j in range(min_J,max_J+1):
                prova = str(j)
        
                for z in range(len(prova), grandezza):
                    prova = "0" + prova
                ok = True
                for z in range(grandezza):
                    if J[z] != "?":
                        if J[z] != prova[z]:
                            ok = False
                if ok:
                            
                    delta = abs(c-j)
                    #print (c,j,diff,delta)
                    if delta == 0:
                        trovato = True
                        diff = 0
                        break
                    else:
                        if delta < diff:
                            #print ("trovato")
                            diff = delta
                            c_temp = c
                            j_temp = j
            if trovato:
                break
    if not trovato:
        c = c_temp
        j = j_temp
        
    c = str(c)
    j = str(j)

    for z in range(len(c), grandezza):
        c = "0"+c
    for z in range(len(j), grandezza):
        j = "0"+j
    ris = c + " " +j
        
    txt_output = txt_output + "Case #"+str(n+1)+": "+ris+"\n"
##    if n == 0:
##        break
    

    
txt_output = txt_output[:-1]   
print (txt_output)
t2 = time.time()
#print (t2-t1)
foutput.write(txt_output)
foutput.close()
finput.close()
