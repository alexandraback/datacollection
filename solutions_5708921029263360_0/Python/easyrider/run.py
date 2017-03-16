#!/usr/bin/python3
import numpy

nr_of_tasks = int(input())


for task_index in range(1,nr_of_tasks+1):
    jackets, pants, shirts, comb  = (int(item) for item in input().split(" "))
    max_nr_of_comb = jackets*pants*shirts
    combinations = []
    for i in range(1,jackets+1):
        for i2 in range(1, pants+1):
            for i3 in range(1,shirts+1):
                combinations.append([i, i2, i3])

    ab = {}
    ac = {}
    bc = {}

    final_outfit_list = []
    next_step = []
    if comb > 0:
        for ind,  outfit in enumerate(combinations):
            comb_dec = 0
            if (outfit[0], outfit[1]) in ab:
                next_step.append(outfit)
                continue
            elif (outfit[0], outfit[2]) in ac:
                next_step.append(outfit)
                continue
            elif (outfit[1], outfit[2]) in bc:
                next_step.append(outfit)
                continue
            final_outfit_list.append(outfit)
            ab[(outfit[0], outfit[1])] = 1
            ac[(outfit[0], outfit[2])] = 1
            bc[(outfit[1], outfit[2])] = 1

        if comb > 1:
            for outfit in next_step:
                if (outfit[0], outfit[1]) in ab:
                    if ab[(outfit[0], outfit[1])] == comb:
                        continue
                if (outfit[0], outfit[2]) in ac:
                    if ac[(outfit[0], outfit[2])] == comb:
                        continue
                if (outfit[1], outfit[2]) in bc:
                    if bc[(outfit[1], outfit[2])] == comb:
                        continue

                final_outfit_list.append(outfit)
                if (outfit[0], outfit[1]) not in ab:
                    ab[(outfit[0], outfit[1])] = 1
                else:
                    ab[(outfit[0], outfit[1])] = ab[(outfit[0], outfit[1])] + 1
                if (outfit[0], outfit[2]) not in ac:
                    ac[(outfit[0], outfit[2])] = 1
                else:
                    ac[(outfit[0], outfit[2])] = ac[(outfit[0], outfit[2])] + 1

                if (outfit[1], outfit[2]) not in bc:
                    bc[(outfit[1], outfit[2])] = 1
                else:
                    bc[(outfit[1], outfit[2])] = bc[(outfit[1], outfit[2])] + 1


    result = len(final_outfit_list)

    print("Case #{task}: {result}".format(task=task_index,
                             result=result))
    for item in final_outfit_list:
        print(" ".join([str(i) for i in item]))
