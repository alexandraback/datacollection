def ProblemA(filename):
    import string
    File = open('/CodeJam/' + filename,'r');
    Data = File.read();
    Start = 0;
    End = Data.find('\n',Start);
    T = int(Data[Start:End])
    Output = open('/CodeJam/' + 'AOut.txt','w');

    t = 0;
    while (t < T):
        Start = End + 1;
        End = Data.find(' ',Start);
        MaxShy = int(Data[Start:End]);
        
        Here = End + 1;
        Friends = 0;
        Excess = int(Data[Here])
        Shy = 0;
        while (Shy < MaxShy):
            Here = Here + 1;
            Excess = Excess - 1;
            if (Excess < 0):
                Friends = Friends + 1;
                Excess = 0;
            Excess = Excess + int(Data[Here]);
            Shy = Shy + 1;

        ThisCase = 'Case #' + str(t+1) + ': ' + str(Friends);
        print(ThisCase);
        Output.write(ThisCase + '\n');

        End = Data.find('\n',End);
        t = t + 1;

    Output.close();



