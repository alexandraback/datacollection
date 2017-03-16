fin = open('/Users/alex/Desktop/codejam/test.in', 'r')
fout = open('/Users/alex/Desktop/codejam/test.out', 'w')
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
    for line in lines:
        if "." in line:
            answer+="Game has not completed\n"
            return answer
    answer.append+="Draw\n"
    return answer
        

for i in range(int(n)):
    lines = [fin.readline().strip() for j in range(4)]
    answer = test(lines, i)
    print answer
    fout.write(answer)
    fin.readline()            
    

    


fin.close()
fout.close()
