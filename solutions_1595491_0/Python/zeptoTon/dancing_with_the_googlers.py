def cal_score(people, suprise, wanted_score, score_list):
    count = 0

    if wanted_score == 0:
        return str(len(score_list)) 

    good_score = wanted_score * 3 -2
    suprise_score = wanted_score * 3 - 4

    if good_score <= 0:
        good_score = wanted_score

    if suprise_score <= 0:
        suprise_score = wanted_score

    for score in score_list:
        if  int(score) >=  good_score:
            count += 1
        elif int(score) >= suprise_score and suprise :
            count += 1
            suprise -= 1

    return str(count)


def main():
    f = open('B-small-attempt0.in', 'r')
    r = open('B-small-attempt0.in-result', 'w')

    while True:
        line = f.readline()
        if not line:
            break
        caseNum = int(line)
        for i in range(caseNum):
            lines = f.readline().rstrip()
            temp = lines.split(' ')
            result_line = 'Case #' + str(i + 1) + ': ' + cal_score(int(temp[0]), int(temp[1]), int(temp[2]), temp[3::])
            r.write(result_line + '\n')
            print result_line

    f.close()
    r.close()


if __name__ == '__main__':
    main()
