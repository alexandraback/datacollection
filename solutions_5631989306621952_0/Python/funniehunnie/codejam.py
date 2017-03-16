case = int(input().strip())
for i in range(case):
    string = list(input().strip())
    
    newString = [string[0]]
    for j in string[1:]:
        if j < newString[0]:
            newString.append(j)
        else:
            newString.insert(0,j)
    print("Case #%i: %s" %(i+1, ''.join(newString)))
