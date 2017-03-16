from itertools import groupby
from math import factorial


in_file = "B-small-attempt1.in"
out_file = "train_cars.out"

out = open(out_file, 'w')

def numberOfValidTrain(car_num, car_list):
    valid_number = 1

    new_list = []
    # merge the same chars in one string
    for car in car_list:
        new_list.append(''.join(c for c, _ in groupby(car)))

    # count the duplicated strings with same character
    car_dict = dict([(x, new_list.count(x)) for x in set(new_list)])
    for elem in car_dict:
        if len(elem) == 1:
            valid_number *= factorial(car_dict[elem])

    # get keys list
    new_list = car_dict.keys()
    while needMerge(new_list):
        force_break = False
        for n in range(len(new_list)):
            if force_break:
                break
            for x in range(len(new_list)):
                if force_break:
                    break;
                if n != x:
                    if new_list[n][-1] == new_list[x][0]:
                        newString = new_list[n] + new_list[x][1:]
                        removeA = new_list[n]
                        removeB = new_list[x]
                        new_list.remove(removeA)
                        new_list.remove(removeB)
                        new_list.append(newString)
                        force_break = True
        if force_break == False:
            return 0
    return valid_number * factorial(len(new_list))

def needMerge(car_list):
    for n in range(len(car_list)):
        for c in car_list[n]:
            for x in range(len(car_list)):
                if x != n and c in car_list[x]:
                    return True
    return False

def result_out(case, result):
    out.write("Case #" + str(case) + ": " + str(result) + '\n')


with open(in_file) as f:
    case_num = int(f.readline())
    for case in range(1, case_num + 1):
        car_num = int(f.readline().strip())
        car_list = f.readline().strip().split(' ')
        result = numberOfValidTrain(car_num, car_list)
        result_out(case, result)



