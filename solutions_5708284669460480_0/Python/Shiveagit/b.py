# Created By: Bryce Besler
import math;

T = int(raw_input());
for t in xrange(T):
    row = str(raw_input()).split(' ');
    K_len = int(row[0]);
    L_len = int(row[1]);
    S = int(row[2]);

    K = str(raw_input());
    L = str(raw_input());

    # Generate histograms
    K_hist = {};
    for elem in K:
        if elem not in K_hist:
            K_hist[elem] = K.count(elem);

    L_hist = {};
    for elem in L:
        if elem not in L_hist:
            L_hist[elem] = L.count(elem);

    # Test if L in K and possible in S key strokes
    isIn = True;
    for key in L_hist:
        if key not in K_hist:
            isIn = False;
            break;

    if S < L_len:
        isIn = False;

    if(isIn == True):
        # Calculate worst case
        temp = L[1:];
        j = 0;
        for i in xrange(L_len - 1):
            if temp[i] == L[j]:
                j += 1;
            else:
                j = 0;
        L_len_prime = L_len - j;

        worst_case = int(math.floor((S - L_len)/L_len_prime)) + 1;

        # Calcualte average
        temp = 1;
        for elem in L_hist:
            temp = temp*(K_hist[elem] ** L_hist[elem]);
        average_case = worst_case * temp / float(K_len ** L_len);

        print "Case #{t}: {ans}".format(t=t+1, ans= worst_case - average_case);

    else:
        print "Case #{t}: {ans}".format(t=t+1, ans=0.0)

