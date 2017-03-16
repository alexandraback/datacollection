new_lang_map = {}

def populate_new_lang_map():
    text1 = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"
    sol =   "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"
    for i in range(0,len(text1)):
        if text1[i] not in new_lang_map:
            new_lang_map[text1[i]] = sol[i]

    new_lang_map['q'] = 'z'
    new_lang_map['z'] = 'q'    

def convert_main(file_name):
    f = open(file_name,"r")
    output_file = open("output.txt","w")    
    no_of_input = int(f.readline())
    for case in range(1,no_of_input+1):    
        result = convert(f.readline().strip())
        output_file.write("Case #"+str(case)+": "+result+"\n")
        case +=1
    output_file.close()
    f.close()

def convert(line):
    output = ""
    for i in range(0,len(line)):
        output +=new_lang_map[line[i].lower()]
    return output
        
        
        


populate_new_lang_map()
convert_main("A-small-attempt0.in")
