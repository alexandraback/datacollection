
def dance_baby(input_file):
    f = open(input_file,"r")
    output_file = open("output.txt","w")  
    no_of_input = int(f.readline())
    for case in range(1,no_of_input+1):        
        result = calculate(f.readline().strip())
        output_file.write("Case #"+str(case)+": "+str(result)+"\n")
    f.close()
    output_file.close()

def calculate(line):
    split_input = line.split()
    number_of_dancers = int(split_input[0])
    no_of_suprises_left = int(split_input[1])
    par_score = int(split_input[2])
    result = 0    
    for count in range(3,number_of_dancers+3):        
        score = int(split_input[count])
        min_score = par_score * 3        
        if score >= min_score or min_score - score <= 2:
            result +=1
        elif score >= par_score and (min_score - score) <= 4 and (no_of_suprises_left >0):                      
            result +=1
            no_of_suprises_left -=1

    return result
        
dance_baby("B-small-attempt1.in")        
    
        











