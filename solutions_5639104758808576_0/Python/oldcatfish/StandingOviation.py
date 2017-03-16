infile = open('A-small-attempt0.in', 'r');
num_test = int(next(infile));
for indx_test in range(num_test):
    s_text = next(infile);
    s_max = int(s_text.split()[0]);
    s = s_text.split()[1];
    s_sum = 0;
    s_need = 0;
    for indx in range(s_max+1):
        s_sum += int(s[indx]);
        if s_sum < indx+1:
            s_need += indx + 1 - s_sum;
            s_sum = indx + 1;
    print('Case #' + str(indx_test + 1) + ': ', end="");
    print(str(s_need));
    