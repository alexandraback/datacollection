fin = open('/Users/alex/Desktop/codejam/A-large-attempt0.in', 'r')
fout = open('/Users/alex/Desktop/codejam/A-large-attempt0.out', 'w')
n =fin.readline().strip()



def test(lines, i):
    answer = "Case #"+str(i+1)+": "

    for line in lines:
        if "." not in line and "X" not in line:
            answer+="O won\n"
            return answer
        if "." not in line and "O" not in line:
            answer+="X won\n"
            return answer
    for i in range(4):
        column = [line[i] for line in lines]
        if "." not in column and "X" not in column:
            answer+="O won\n"
            return answer
        if "." not in column and "O" not in column:
            answer+="X won\n"
            return answer

    diag1 = [lines[i][i] for i in range(4)]
    diag2 = [lines[i][3-i] for i in range(4)]

    if ("." not in diag1 and "X" not in diag1) or ("." not in diag2 and "X" not in diag2):
        answer+="O won\n"
        return answer
    if  ("." not in diag1 and "O" not in diag1) or ("." not in diag2 and "O" not in diag2):
        answer+="X won\n"
        return answer
    
    for line in lines:
        if "." in line:
            answer+="Game has not completed\n"
            return answer
    answer+="Draw\n"
    return answer
        

for i in range(int(n)):
    lines = [fin.readline().strip() for j in range(4)]
    answer = test(lines, i)
    print answer
    fout.write(answer)
    fin.readline()            
    

    


fin.close()
fout.close()
