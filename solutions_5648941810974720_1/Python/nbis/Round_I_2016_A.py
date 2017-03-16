import math, time



t1 = time.time()    
n= 0
finput = open("Round_I_2016_A_sample_input.txt","r")
foutput = open("output.txt","w")
testcase = []
for line in finput:
    if line[-1] == "\n":
        #dati = line[:-1].split()
        dati = line[:-1]
    else:
        #dati = line.split()
        dati = line
    if n == 0:
        T = int(dati)
          
    else:
        if n <= T:
           testcase.append(dati)
                
    n +=1

numbers = {0:"ZERO", 1:"ONE",2:"TWO",3:"THREE", 4:"FOUR",5:"FIVE",
           6:"SIX", 7:"SEVEN",8:"EIGHT",9:"NINE"}
primo = {0: "Z",2:"W",4:"U",6:"X",8:"G"}
primo_list = [0,2,4,6,8]
secondo = {1:"O",3:"H", 5:"F",7:"S",9:"N"}
secondo_list = [1,3,5,7,9]
print (T,testcase)
txt_output = ""

for n in range(T):
    tel =[]
    partenza  = 0
    numero = list(testcase[n])
    
    for c in primo_list:
        
        while primo[c] in numero:
            tel.append(c)
            cifre = numbers[c]
            for j in cifre:
                numero.remove(j)
    for c in secondo_list:
        while secondo[c] in numero:
            tel.append(c)
            cifre = numbers[c]
            
            for j in cifre:
               
                numero.remove(j)
            
    
    tel.sort()
   
    ris = ""
    for t in tel:
        ris = ris+str(t)
    txt_output = txt_output + "Case #"+str(n+1)+": "+ris+"\n"
    
    

    
txt_output = txt_output[:-1]   
print (txt_output)
t2 = time.time()
#print (t2-t1)
foutput.write(txt_output)
foutput.close()
finput.close()
