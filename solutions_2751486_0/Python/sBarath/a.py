def findans(word,n):
    arr = []
    for i in range(len(word) - n + 1):
        if cons(word[i:i+n]):
            arr.append(word[i:i+n])
    count = 0
    for i in range(len(word)):
        str1 = word[i:]
        flag = 0
        for j in range(len(arr)):
            
            if arr[j] in str1:
                flag = 1
        if flag == 1:
            count += 1
    for i in range(len(word)):
        str1 = word[:len(word)-i]
        flag = 0
        for j in range(len(arr)):
            
            if arr[j] in str1:
                flag = 1
        if flag == 1:
            count += 1
    if len(arr) ==2 and arr[0] == arr[1] :
        count += 3
    if count == 0:
        return 0
    return count - 1



def cons(str1):
    if 'a' not in str1 and 'e' not in str1 and 'i' not in str1 and 'o' not in str1 and 'u' not in str1:
        return True
    else:
        return False

def runprog(FILE):
    infile = open(FILE,'r')
    outfile = open('a1.out','w')
    line1 = infile.readline()
    T = int(line1.strip('\n'))
    for i in range(T):
        
        arr = ((infile.readline()).strip('\n')).split(' ')
        ans = findans(arr[0],int(arr[1]))

        
        outfile.write('Case #' + str(i+1) + ': ' + str(int(ans)) + '\n')

    infile.close()
    outfile.close()
    

