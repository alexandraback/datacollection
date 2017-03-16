def work(case_vars):
    c, f, x = case_vars
    time = 0.
    cookies = 0.
    rate = 2.

    while cookies < x:
        time += min(c, x-cookies)/rate

        #not correct amount but it shouldn't matter
        cookies += c

        st1 = (x-cookies)/rate
        st2 = (x-cookies+c)/(rate+f)

        if st1 > st2:
            rate += f
            cookies -= c
    
    return time


def get_cases(f):
    #read num of cases
    cases = int(f.readline())
    for case in range(cases):
        #read a, b
        c, _f, x = [float(i) for i in f.readline().split()]

        yield case+1, c, _f, x


def main():
    flag = 2

    input_name = "test.in" if flag == 0 else "B-small-attempt0.in" if flag == 1 else "B-large.in"
    output_name = input_name[:-2] + "out"
    print input_name
    print output_name

    with open(input_name, 'rb') as in_file,  open(output_name, 'w') as out_file:
        for case_vars in get_cases(in_file):
            case = case_vars[0]
            print case
            c = work(case_vars[1:])
            out_file.write("Case #%d: %.7f" % (case, c) + "\n")


main()
