def ProblemA(filename):
    import string
    File = open('/CodeJam/' + filename,'r');
    Data = File.read();
    File.close()
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




def ProblemB(filename):
    import string
    import copy
    File = open('/CodeJam/' + filename,'r');
    Data = File.read();
    File.close()
    Start = 0;
    End = Data.find('\n',Start);
    T = int(Data[Start:End]);
    Output = open('/CodeJam/' + 'BOut.txt','w');

    t = 0;
    while (t < T):
        Start = End + 1;
        End = int(Data.find('\n',Start));
        D = int(Data[Start:End]);
        Start = End + 1;
        
        # Read in the diners
        Diners = [];
        d = 0;
        while (d < (D-1)):
            End = int(Data.find(' ',Start));
            Diners.append(int(Data[Start:End]));
            Start = End + 1;
            d = d + 1;
        End = int(Data.find('\n',Start));
        Diners.append(int(Data[Start:End]));
        Start = End + 1;
        d = d + 1;

        # Try all pancake stack limits
        PMax = max(Diners);
        PLim = PMax;
        AllTimes = [0]*PLim;
        ETimes = [0]*PLim;
        STimes = [0]*PLim;
        while (PLim > 0):
            TheseDiners = copy.copy(Diners);
            #print(TheseDiners);

            # Distribute the pancakes until the maximum is no more than PLim
            Special = 0;
            Eating = 0;
            Go = (PLim < PMax);
            while (Go):
                PMax = max(TheseDiners);
                PCount = TheseDiners.count(PMax);
                PShift = int(PMax/2);
                # Redistribute the pancakes
                d = 0;
                Dnow = len(TheseDiners);
                while (d < Dnow):
                    PHere = TheseDiners[d];
                    if (PHere == PMax):
                        TheseDiners[d] = PHere - PShift;
                        TheseDiners.append(PShift);
                    d = d + 1;
                Special = Special + PCount;
                if (max(TheseDiners) <= PLim):
                    Go = False;
             
            # Calculate total breakfast time for this limit
            #print(TheseDiners);
            Eating = max(TheseDiners);
            ThisTime = Special + Eating;
            PLim = PLim - 1;
            AllTimes[PLim] = ThisTime;
            ETimes[PLim] = Eating;
            STimes[PLim] = Special;

        # Choose the lowest time among all pancake limits
        #print(ETimes);
        #print(STimes);
        #print(AllTimes);
        TotalTime = min(AllTimes);

        # Report the output
        ThisCase = 'Case #' + str(t+1) + ': ' + str(TotalTime);
        print(ThisCase);
        Output.write(ThisCase + '\n');

        # Advance to the next case 
        t = t + 1;

    Output.close();




def ProblemC(filename):
    import string
    File = open('/CodeJam/' + filename,'r');
    Data = File.read();
    File.close()
    Start = 0;
    End = Data.find('\n',Start);
    T = int(Data[Start:End]);
    Output = open('/CodeJam/' + 'COut.txt','w');

    Mult = [[0,1,2,3,4,5,6,7],[1,4,3,6,5,0,7,2],[2,7,4,1,6,3,0,5],[3,2,5,4,7,6,1,0],[4,5,6,7,0,1,2,3],[5,0,7,2,1,4,3,6],[6,3,0,5,2,7,4,1],[7,6,1,0,3,2,5,4]];

    t = 0;
    while (t < T):
        Start = End + 1;
        End = int(Data.find(' ',Start));
        L = int(Data[Start:End]);
        Start = End + 1;
        End = int(Data.find('\n',Start));
        X = int(Data[Start:End]);
        Start = End + 1;

        # Read in the string
        Here = Start;
        z = 0;
        MyString = [0]*L;
        while (z < L):
            MyChar = Data[Here];
            if (MyChar == 'i'):
                MyNum = 1;
            if (MyChar == 'j'):
                MyNum = 2;
            if (MyChar == 'k'):
                MyNum = 3;
            MyString[z] = MyNum;
            Here = Here + 1;
            z = z + 1;

        # Take the product of the string
        MyProd = 0;
        z = 0;
        while (z < L):
            MyProd = Mult[MyProd][MyString[z]];
            z = z + 1;

        # Check if the entire product is -1
        Failure = False;
        if (MyProd == 0):
            Failure = True;
        elif (MyProd == 4):
            if (X%2 == 0):
                Failure = True;
        else:
            if (X%4 != 2):
                Failure = True;

        Xrem = X;
        Pos = 0;
        MaxLoop = 3;

        # Look for an i-segment
        Loop = 0;
        Go = not(Failure);
        z = Pos;
        ThisSeg = 0;
        while (Go):
            ThisSeg = Mult[ThisSeg][MyString[z]];
            z = z + 1;
            if (z == L):
                z = 0;
                Loop = Loop + 1;
                Xrem = Xrem - 1;
                if ((Loop == MaxLoop) or (Xrem == 0)):
                    Go = False;
                    Failure = True;
            if ((ThisSeg == 1) or (ThisSeg == 5)):
                Go = False;
                Pos = z;
                Failure = False;

        # Look for a j-segment
        Loop = 0;
        Go = not(Failure);
        z = Pos;
        ThisSeg = 0;
        while (Go):
            ThisSeg = Mult[ThisSeg][MyString[z]];
            z = z + 1;
            if (z == L):
                z = 0;
                Loop = Loop + 1;
                Xrem = Xrem - 1;
                if ((Loop == MaxLoop) or (Xrem == 0)):
                    Go = False;
                    Failure = True;
            if ((ThisSeg == 2) or (ThisSeg == 6)):
                Go = False;
                Pos = z;
                Failure = False;

        # Look for a k-segment
        Loop = 0;
        Go = not(Failure);
        z = Pos;
        ThisSeg = 0;
        while (Go):
            ThisSeg = Mult[ThisSeg][MyString[z]];
            z = z + 1;
            if (z == L):
                z = 0;
                Loop = Loop + 1;
                Xrem = Xrem - 1;
                if ((Loop == MaxLoop) or (Xrem == 0)):
                    Go = False;
                    Failure = True;
            if ((ThisSeg == 3) or (ThisSeg == 7)):
                Go = False;
                Pos = z;
                Failure = False;

        # Report the result
        if (Failure):
            Report = "NO";
        else:
            Report = "YES";
        ThisCase = 'Case #' + str(t+1) + ': ' + Report;
        print(ThisCase);
        Output.write(ThisCase + '\n');

        # Advance to the next case 
        End = Data.find('\n',Start);
        t = t + 1;

    Output.close();




def ProblemD(filename):
    import string
    File = open('/CodeJam/' + filename,'r');
    Data = File.read();
    File.close()
    Start = 0;
    End = Data.find('\n',Start);
    T = int(Data[Start:End]);
    Output = open('/CodeJam/' + 'DOut.txt','w');

    t = 0;
    while (t < T):
        Start = End + 1;
        End = int(Data.find(' ',Start));
        X = int(Data[Start:End]);
        Start = End + 1;
        End = int(Data.find(' ',Start));
        R = int(Data[Start:End]);
        Start = End + 1;
        End = int(Data.find('\n',Start));
        C = int(Data[Start:End]);
        Impossible = False;

        # Check if there is an enclosing X-omino
        if (X > 6):
            Impossible = True;

        # Check if a long X-omino automatically wins
        if (R > C):
            BigD = R;
            LilD = C;
        else:
            BigD = C;
            LilD = R;
        if (X > BigD):
            Impossible = True;

        # Check if the X-ominoes evenly fit in the grid
        Squares = R*C;
        if (Squares%X != 0):
            Impossible = True;

        # Check if the smaller dimension poses an issue
        if ((X == 6) or (X == 5)):
            if (LilD < 4):
                Impossible = True;
        if (X == 4):
            if (LilD < 3):
                Impossible = True;
        if (X == 3):
            if (LilD < 2):
                Impossible = True;
        if (X < 3):
            if (LilD < 1):
                Impossible = True;

        # Report the result
        if (Impossible):
            Report = 'RICHARD';
        else:
            Report = 'GABRIEL';
        ThisCase = 'Case #' + str(t+1) + ': ' + Report;
        print(ThisCase);
        Output.write(ThisCase + '\n');

        # Advance to the next case
        t = t + 1;

    Output.close();
