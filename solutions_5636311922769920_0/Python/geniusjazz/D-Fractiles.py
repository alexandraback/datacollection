def main():
    f = open("D-small-attempt1.in", 'r')
    output = open("D-small-attempt1.out",'w')

    line_num = 0
    for line in f:
        if (line_num == 0):
            T = line
        else:
            K, C, S = line.split(" ")
            answer = "Case #" + str(line_num) + ":"

            for i in range(0, int(S)):
                num = 1 + (int(K)**(int(C)-1))*i
                answer += " " + str(num)
            output.write('{}\n'.format(answer))
        line_num += 1

main()
