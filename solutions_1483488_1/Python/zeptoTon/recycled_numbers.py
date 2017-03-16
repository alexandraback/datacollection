def pumute(lower, upper):
    digit = len(str(lower))
    count = 0
    for i in range(lower, upper+1):
        first = str(i)
        double_count = {}
        for j in range(1, digit):
            num_list = first[-j:] + first[:-j]
            
            #print num_list
            if int(num_list)>i and int(num_list)<=upper and int(num_list)!=i and not(double_count.has_key(num_list)):
                count += 1
                double_count[num_list] = True
                

    return str(count)
    #         if not((int(num_list)<lower) or (int(num_list)>upper)) and int(num_list)!=i:
    #             count += 1
    #             print num_list

    # print count
    # return str(count / 2)


def main():
    f = open('C-large.in', 'r')
    r = open('C-large.in-result', 'w')

    while True:
        line = f.readline()
        if not line:
            break
        caseNum = int(line)
        for i in range(caseNum):
            lines = f.readline().rstrip()
            temp = lines.split(' ')
            result_line = 'Case #' + str(i + 1) + ': ' + pumute(int(temp[0]), int(temp[1]))
            r.write(result_line + '\n')
            print result_line

    f.close()
    r.close()


if __name__ == '__main__':
    main()
