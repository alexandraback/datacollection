
import math


def solve(coder,jammer):
    return_coder = ""
    return_jammer = ""

    coder_missing_indexes = [i for i in range(len(coder)) if coder[i] == "?"]
    jammer_missing_indexes = [i for i in range(len(jammer)) if jammer[i] == "?"]

    coder_filled_indexes = [i for i in range(len(coder)) if coder[i] != "?"]
    jammer_filled_indexes = [i for i in range(len(jammer)) if jammer[i] != "?"]

    joined_missing_indexes = []
    for value in coder_missing_indexes:
        if value in jammer_missing_indexes:
            joined_missing_indexes.append(value)

    joined_filled_indexes = []
    for value in coder_filled_indexes:
        if value in jammer_filled_indexes:
            joined_filled_indexes.append(value)

    for value in joined_missing_indexes:
        coder_missing_indexes.remove(value)
        jammer_missing_indexes.remove(value)

    for value in joined_filled_indexes:
        coder_filled_indexes.remove(value)
        jammer_filled_indexes.remove(value)

    if len(joined_filled_indexes) == 0:
        for i in range(len(coder)):
            if i in coder_missing_indexes:
                return_coder += jammer[i]
                return_jammer += jammer[i]
            elif i in jammer_missing_indexes:
                return_coder += coder[i]
                return_jammer += coder[i]
            elif i in joined_missing_indexes:
                return_coder += "0"
                return_jammer += "0"
    else:
        for i in range(len(coder)):
            if i in joined_filled_indexes:
                return_coder += coder[i]
                return_jammer += jammer[i]
            elif i in joined_missing_indexes:

                if return_coder != "":
                    coder_int = int(return_coder)
                else:
                    coder_int = 0
                if return_jammer != "":
                    jammer_int = int(return_jammer)
                else:
                    jammer_int = 0

                if coder_int < jammer_int:
                    return_coder += "9"
                    return_jammer += "0"
                elif jammer_int < coder_int:
                    return_coder += "0"
                    return_jammer += "9"
                else:
                    return_coder += "0"
                    return_jammer += "0"
            else:
                if i < len(coder) - 1 and i+1 in joined_filled_indexes:
                    if i in coder_missing_indexes:
                        jammer_int = int(return_jammer + jammer[i] + jammer[i + 1])
                        min_dist = 1000000000000000000000000000000000000000000
                        min_digit = "0"
                        for v in [str(b) for b in range(10)]:
                            m = math.fabs(int(return_coder+ v + coder[i + 1]) - jammer_int)
                            if m < min_dist:
                                min_dist = m
                                min_digit = v

                        return_coder += min_digit
                        return_jammer += jammer[i]

                    else:
                        coder_int = int(return_coder+coder[i]+coder[i+1])
                        min_dist = 1000000000000000000000000000000000000000000
                        min_digit = []
                        for v in [str(b) for b in range(10)]:
                            m = math.fabs(int(return_jammer+v+jammer[i+1])-coder_int)
                            if m < min_dist:
                                min_dist = m
                                min_digit = v

                        return_coder += coder[i]
                        return_jammer += min_digit

                else:
                    if i in coder_missing_indexes:
                        jammer_int = int(return_jammer + jammer[i])
                        min_dist = 1000000000000000000000000000000000000000000
                        min_digit = "0"
                        for v in [str(b) for b in range(10)]:
                            m = math.fabs(int(return_coder + v) - jammer_int)
                            if m < min_dist:
                                min_dist = m
                                min_digit = v

                        return_coder += min_digit
                        return_jammer += jammer[i]

                    else:
                        coder_int = int(return_coder + coder[i])
                        min_dist = 1000000000000000000000000000000000000000000
                        min_digit = []
                        for v in [str(b) for b in range(10)]:
                            m = math.fabs(int(return_jammer + v) - coder_int)
                            if m < min_dist:
                                min_dist = m
                                min_digit = v

                        return_coder += coder[i]
                        return_jammer += min_digit

    return return_coder + " " + return_jammer



def main():
    input_file = open('B-small-attempt2.in', 'r')
    output_file = open('B-small.out', 'w')
    number_of_cases = int(input_file.readline().strip())
    for i in range(1, number_of_cases + 1):
        v = input_file.readline().strip().split(" ")
        result = solve(v[0], v[1])
        print result
        output_file.write("Case #" + str(i) + ": " + result + "\n")

    input_file.close()
    # v = "43? 7?3".split(" ")
    # result = solve(v[0], v[1])
    # print result


if __name__ == "__main__":
    main()