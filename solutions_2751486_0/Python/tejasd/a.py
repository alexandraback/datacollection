import string

consonants = list(string.ascii_lowercase)
consonants.remove('a')
consonants.remove('e')
consonants.remove('i')
consonants.remove('o')
consonants.remove('u')

def find_start_points(name, n): #can be imporved
    start_list = list()
    for i in range(name.__len__() - n + 1):
        isConsonant = True
        for subchar in name[i:i+n]:
            if not(subchar in consonants):
                isConsonant = False
                break
        if isConsonant:
            start_list.append(i)
    return start_list

def find_n_value(name, n):
    start_list = find_start_points(name, n)
    start = 0
    end = -1
    
    n_value = start_list.__len__()
    for i in range(n+1, name.__len__() + 1):
        start = 0
        end = -1
        isDone = False
        for start_point in start_list:
            if start_point-(i-n) <= end:
                start = end + 1
            else:
                start = start_point-(i-n)
            #determine end
            if start_point+i >= name.__len__():
                end = name.__len__() - i
                isDone = True
            else:
                end = start_point

            n_value += end-start+1
            if (isDone):
                break
        
    
    return n_value

if __name__ == "__main__":
    tcases = int(raw_input())
    for itc in range(tcases):
        name, n = raw_input().split()        
        print 'Case #' + str(itc+1) + ': ' + str(find_n_value(name, int(n)))
        
