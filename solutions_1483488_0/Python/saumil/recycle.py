def recycled_number(input_file):
    f = open(input_file,"r")
    output_file = open("output.txt","w")
    no_of_input =int( f.readline())
    sorted_list = []
    for case in range(1,no_of_input+1):
        numbers = f.readline().split()
        n1 = int(numbers[0])
        n2 = int(numbers[1])
        result = 0
        dict_map = {}
        for number in range(n1,n2+1):            
            str_number = str(number)
            length = len(str_number)
            temp_list = []
            for i in range(0,length):                
                temp_str = str_number[i:]+str_number[:i]                
                temp = int(temp_str)
                if(temp > number and temp <= n2 and (temp not in temp_list) ):                    
                    result +=1
                    temp_list.append(temp)
        output_file.write("Case #"+str(case)+": "+str(result)+"\n")            
      
    f.close()
    output_file.close()

recycled_number("C-small-attempt0.in")
                
            
            
