using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static int m_NumberOfCases;
        static List<InputCase> m_InputCases;
        static List<string> m_OutputCases;
        static double m_Accuracy = 20;
        static int m_Angle0 = 0;
        static int m_Angle90 = 9000;
        static int m_Angle180 = 18000;
        static int m_Angle270 = 27000;
        static void Main(string[] args)
        {
            GetInput();
            Solve();
            WriteOutput();

            Console.WriteLine("Done!");
            Console.ReadKey();
        }

        private static void GetInput()
        {
            System.IO.StreamReader r = new System.IO.StreamReader("D-small-attempt1.in");
            string line = r.ReadLine();
            m_NumberOfCases = Convert.ToInt32(line.Trim());
            m_InputCases = new List<InputCase>(m_NumberOfCases);
            for (int c = 0; c < m_NumberOfCases; ++c)
            {
                line = r.ReadLine();
                string[] digits = line.Split(' ');
                int rowCount = Convert.ToInt32(digits[0]);
                int columnCount = Convert.ToInt32(digits[1]);
                int d = Convert.ToInt32(digits[2]) * 1000000;
                InputCase temp = new InputCase(rowCount, columnCount, d, 1000000, 1000000);
                for (int i = 0; i < rowCount; ++i)
                {
                    line = r.ReadLine();
                    int j = 0;
                    foreach (char item in line)
                    {
                        if (item == '#')
                            temp.SetUnit(j, rowCount - i - 1, UnitType.Mirror);
                        else
                            if(item == 'X')
                                temp.SetUnit(j, rowCount - i - 1, UnitType.Im);
                        j++;
                    }
                }
                m_InputCases.Add(temp);
            }
            r.Close();
        }
        private static void WriteOutput()
        {
            System.IO.StreamWriter w = new System.IO.StreamWriter("Output.txt");
            int i = 1;
            foreach(string item in m_OutputCases)
                w.WriteLine(string.Format("Case #{0}: {1}", i++, item));
            w.Flush();
            w.Close();
        }

        private static void Solve()
        {
            m_OutputCases = new List<string>(m_NumberOfCases);
            foreach (InputCase item in m_InputCases)
            {
                int returnValue = 0;
                for (int angle = 0; angle < m_Angle180 * 2; ++angle)
                {
                    bool flag = false;
                    if (angle == m_Angle0 || angle == m_Angle90 || angle == m_Angle180 || angle == m_Angle270)
                        flag = SendRay1(angle, item);
                    else
                        flag = SendRay(angle, item);
                    if (flag)
                        returnValue++;
                }
                m_OutputCases.Add(returnValue.ToString());
            }
        }
        private static bool SendRay1(int angle, InputCase inputCase)
        {
            Unit currentUnit = inputCase.ImUnit;
            double d = inputCase.D;
            int xPosModify = 0;
            int yPosModify = 0;
            if (angle == m_Angle0)
                xPosModify = 1;
            else
                if (angle == m_Angle90)
                    yPosModify = 1;
                else
                    if (angle == m_Angle180)
                        xPosModify = -1;
                    else
                        if (angle == m_Angle270)
                            yPosModify = -1;
               
            for (; ; )
            {
                if(currentUnit.UType == UnitType.Im)
                    d -= inputCase.UnitWidth / 2;
                else
                    d -= inputCase.UnitWidth;
                if (d <= 0)
                    return false;
                currentUnit = inputCase.GetUnit(currentUnit.XPosition + xPosModify, currentUnit.YPosition + yPosModify);
                if (currentUnit.UType == UnitType.Mirror)
                    break;
            }
            for (; ; )
            {
                currentUnit = inputCase.GetUnit(currentUnit.XPosition - xPosModify, currentUnit.YPosition - yPosModify);
                if (currentUnit.UType == UnitType.Im)
                {
                    d -= inputCase.UnitWidth / 2;
                    if (d < 0)
                        return false;
                    else
                        return true;
                }
                else
                    d -= inputCase.UnitWidth;
                if (d <= 0)
                    return false;
            }
        }
        private static bool SendRay(int angle, InputCase inputCase)
        {
            Point point = new Point(inputCase.ImUnit.XPosition * inputCase.UnitWidth + inputCase.UnitWidth / 2,
                inputCase.ImUnit.YPosition * inputCase.UnitHeight + inputCase.UnitHeight / 2);
            Unit currentUnit = inputCase.ImUnit;
            double d = inputCase.D;
            // y=a*x + b
            double a = Math.Tan(((double)angle) * Math.PI / m_Angle180);
            double b = point.Y - a * point.X;
            bool forward = true;
            if (angle > m_Angle90 && angle < m_Angle270)
                forward = false;

            double accuracy = m_Accuracy;
            double accurancyMultiplier = 2;
            double part1 = (m_Angle90 + m_Angle0)/6;
            double part2 = (m_Angle90 + m_Angle0)/3;
            if (angle <= part1 || (angle >= m_Angle90 - part1 && angle <= m_Angle90 + part1) ||
                (angle >= m_Angle180 - part1 && angle <= m_Angle180 + part1) ||
                (angle >= m_Angle270 - part1 && angle <= m_Angle270 + part1) || angle >= m_Angle270 + part2)
            {
                accurancyMultiplier = 2;
            }
            else
                if ((angle >= part2 && angle <= m_Angle90 - part2) ||
                                (angle >= m_Angle90 + part2 && angle <= m_Angle180 - part2) ||
                                (angle >= m_Angle180 + part2 && angle <= m_Angle270 - part2) ||
                                (angle >= m_Angle270 + part2 && angle <= m_Angle270 + 2*part2))
                {
                    accurancyMultiplier = 5;
                }
                else
                    accurancyMultiplier = 13;
            
            Unit nextUnit = currentUnit;
            while (d > 0)
            {
                Point boundary;
                currentUnit = nextUnit;
                MirrorType mirrorType;
                BarrierType barrierType = GetBoundaryParams(point, a, b, forward, currentUnit, inputCase,
                    out boundary, out mirrorType, out nextUnit, accuracy);
                double deltaD = Math.Sqrt(Math.Pow((boundary.X - point.X), 2) + Math.Pow((boundary.Y - point.Y), 2));
                d -= deltaD;
                if (d <= 0)
                    break;
                point = boundary;
                if (barrierType == BarrierType.Edge)
                {
                    if (nextUnit.UType == UnitType.Mirror)
                    {
                        switch (mirrorType)
                        {
                            case MirrorType.Up:
                            case MirrorType.Down:
                                a = -a;
                                b = point.Y + (point.Y - b);
                                break;
                            case MirrorType.Left:
                            case MirrorType.Right:
                                a = -a;
                                b = point.Y + (point.Y - b);
                                forward = !forward;
                                break;
                        }
                        nextUnit = currentUnit;
                    }
                    if (nextUnit.UType == UnitType.Im)
                    {
                        double dtemp;
                        if (CheckHit(point, a, b, inputCase, out dtemp, accuracy /*+ m_Accuracy*/))
                        {
                            d -= dtemp;
                            if (d >= 0)
                                return true;
                            break;
                        }
                    }
                    accuracy += accurancyMultiplier * m_Accuracy;
                }
                if (barrierType == BarrierType.Corner)
                {
                    if (nextUnit.UType == UnitType.Mirror)
                    {
                        switch (mirrorType)
                        {
                            case MirrorType.OppositeCorner:
                                d = 0;
                                continue;
                            case MirrorType.UpRight:
                            case MirrorType.DownRight:
                                a = -a;
                                b = point.Y + (point.Y - b);
                                nextUnit = inputCase.GetUnit(currentUnit.XPosition + 1, currentUnit.YPosition);
                                break;
                            case MirrorType.UpLeft:
                            case MirrorType.DownLeft:
                                a = -a;
                                b = point.Y + (point.Y - b);
                                nextUnit = inputCase.GetUnit(currentUnit.XPosition - 1, currentUnit.YPosition);
                                break;
                            case MirrorType.LeftUp:
                            case MirrorType.RightUp:
                                a = -a;
                                b = point.Y + (point.Y - b);
                                forward = !forward;
                                nextUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition + 1);
                                break;
                            case MirrorType.LeftDown:
                            case MirrorType.RightDown:
                                a = -a;
                                b = point.Y + (point.Y - b);
                                forward = !forward;
                                nextUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition - 1);
                                break;
                            case MirrorType.FullCorner:
                                forward = !forward;
                                nextUnit = currentUnit;
                                break;
                        }
                    }
                    if (nextUnit.UType == UnitType.Im)
                    {
                        double dtemp;
                        if (CheckHit(point, a, b, inputCase, out dtemp, accuracy /*+ m_Accuracy*/))
                        {
                            d -= dtemp;
                            if (d >= 0)
                                return true;
                            break;
                        }
                    }
                    accuracy += accurancyMultiplier * m_Accuracy;
                }
            }
            return false;
        }

        private static BarrierType GetBoundaryParams(Point point, double a, double b, bool forward, Unit currentUnit, InputCase inputCase, out Point boundary, 
            out MirrorType mirrorType, out Unit nextUnit, double accuracy)
        {
            BarrierType returnValue = BarrierType.Edge;
            double currentUnitUp = (currentUnit.YPosition + 1) * inputCase.UnitHeight;
            double currentUnitDown = currentUnit.YPosition * inputCase.UnitHeight;
            double currentUnitLeft = currentUnit.XPosition * inputCase.UnitWidth;
            double currentUnitRight = (currentUnit.XPosition + 1) * inputCase.UnitWidth;
            mirrorType = MirrorType.None;
            if (forward)
            {
                double y = a*currentUnitRight + b;
                if (Math.Abs(y - currentUnitUp) < accuracy)
                {
                    returnValue = BarrierType.Corner;
                    boundary = new Point(currentUnitRight, currentUnitUp);
                    nextUnit = inputCase.GetUnit(currentUnit.XPosition + 1, currentUnit.YPosition + 1);
                    Unit upUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition + 1);
                    Unit rightUnit = inputCase.GetUnit(currentUnit.XPosition + 1, currentUnit.YPosition);
                    if (nextUnit.UType == UnitType.Mirror)
                    {
                        if (upUnit.UType == UnitType.Mirror && rightUnit.UType == UnitType.Mirror)
                            mirrorType = MirrorType.FullCorner;
                        else
                            if (upUnit.UType == UnitType.Mirror && rightUnit.UType != UnitType.Mirror)
                                mirrorType = MirrorType.UpRight;
                            else
                                if (upUnit.UType != UnitType.Mirror && rightUnit.UType == UnitType.Mirror)
                                    mirrorType = MirrorType.RightUp;
                                else
                                    mirrorType = MirrorType.OppositeCorner;
                    }
                }
                else
                    if (Math.Abs(y - currentUnitDown) < accuracy)
                    {
                        returnValue = BarrierType.Corner;
                        nextUnit = inputCase.GetUnit(currentUnit.XPosition + 1, currentUnit.YPosition - 1);
                        boundary = new Point(currentUnitRight, currentUnitDown);
                        Unit downUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition - 1);
                        Unit rightUnit = inputCase.GetUnit(currentUnit.XPosition + 1, currentUnit.YPosition);
                        if (nextUnit.UType == UnitType.Mirror)
                        {
                            if (downUnit.UType == UnitType.Mirror && rightUnit.UType == UnitType.Mirror)
                                mirrorType = MirrorType.FullCorner;
                            else
                                if (downUnit.UType == UnitType.Mirror && rightUnit.UType != UnitType.Mirror)
                                    mirrorType = MirrorType.DownRight;
                                else
                                    if (downUnit.UType != UnitType.Mirror && rightUnit.UType == UnitType.Mirror)
                                        mirrorType = MirrorType.RightDown;
                                    else
                                        mirrorType = MirrorType.OppositeCorner;
                        }
                    }
                    else
                        if (y > currentUnitUp)
                        {
                            nextUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition + 1);
                            boundary = new Point((currentUnitUp - b) / a, currentUnitUp);
                            mirrorType = MirrorType.Up;
                        }
                        else
                            if (y < currentUnitDown)
                            {
                                nextUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition - 1);
                                boundary = new Point((currentUnitDown - b) / a, currentUnitDown);
                                mirrorType = MirrorType.Down;
                            }
                            else
                            {
                                nextUnit = inputCase.GetUnit(currentUnit.XPosition + 1, currentUnit.YPosition);
                                boundary = new Point(currentUnitRight, y);
                                mirrorType = MirrorType.Right;
                            }
            }
            else
            {
                double y = a * currentUnitLeft + b;
                if (Math.Abs(y - currentUnitUp) < accuracy)
                {
                    returnValue = BarrierType.Corner;
                    nextUnit = inputCase.GetUnit(currentUnit.XPosition - 1, currentUnit.YPosition + 1);
                    boundary = new Point(currentUnitLeft, currentUnitUp);
                    Unit upUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition + 1);
                    Unit leftUnit = inputCase.GetUnit(currentUnit.XPosition - 1, currentUnit.YPosition);
                    if (nextUnit.UType == UnitType.Mirror)
                    {
                        if (upUnit.UType == UnitType.Mirror && leftUnit.UType == UnitType.Mirror)
                            mirrorType = MirrorType.FullCorner;
                        else
                            if (upUnit.UType == UnitType.Mirror && leftUnit.UType != UnitType.Mirror)
                                mirrorType = MirrorType.UpLeft;
                            else
                                if (upUnit.UType != UnitType.Mirror && leftUnit.UType == UnitType.Mirror)
                                    mirrorType = MirrorType.LeftUp;
                                else
                                    mirrorType = MirrorType.OppositeCorner;
                    }
                }
                else
                    if (Math.Abs(y - currentUnitDown) < accuracy)
                    {
                        returnValue = BarrierType.Corner;
                        nextUnit = inputCase.GetUnit(currentUnit.XPosition - 1, currentUnit.YPosition - 1);
                        boundary = new Point(currentUnitLeft, currentUnitDown);
                        Unit downUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition - 1);
                        Unit leftUnit = inputCase.GetUnit(currentUnit.XPosition - 1, currentUnit.YPosition);
                        if (nextUnit.UType == UnitType.Mirror)
                        {
                            if (downUnit.UType == UnitType.Mirror && leftUnit.UType == UnitType.Mirror)
                                mirrorType = MirrorType.FullCorner;
                            else
                                if (downUnit.UType == UnitType.Mirror && leftUnit.UType != UnitType.Mirror)
                                    mirrorType = MirrorType.DownLeft;
                                else
                                    if (downUnit.UType != UnitType.Mirror && leftUnit.UType == UnitType.Mirror)
                                        mirrorType = MirrorType.LeftDown;
                                    else
                                        mirrorType = MirrorType.OppositeCorner;
                        }
                    }
                    else                
                        if (y > currentUnitUp)
                        {
                            nextUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition + 1);
                            boundary = new Point((currentUnitUp - b) / a, currentUnitUp);
                            mirrorType = MirrorType.Up;
                        }
                        else
                            if (y < currentUnitDown)
                            {
                                nextUnit = inputCase.GetUnit(currentUnit.XPosition, currentUnit.YPosition - 1);
                                boundary = new Point((currentUnitDown - b) / a, currentUnitDown);
                                mirrorType = MirrorType.Down;
                            }
                            else
                            {
                                nextUnit = inputCase.GetUnit(currentUnit.XPosition - 1, currentUnit.YPosition);
                                boundary = new Point(currentUnitLeft, y);
                                mirrorType = MirrorType.Left;
                            }
            }
            return returnValue;
        }
        private static bool CheckHit(Point point, double a, double b, InputCase inputCase, out double d, double accuracy)
        {
            d = 0;
            Point point1 = new Point(inputCase.ImUnit.XPosition * inputCase.UnitWidth + inputCase.UnitWidth / 2,
                inputCase.ImUnit.YPosition * inputCase.UnitHeight + inputCase.UnitHeight / 2);
            double y = a * point1.X + b;
            if (Math.Abs(point1.Y - y) > accuracy)
                return false;
            d = Math.Sqrt(Math.Pow((point1.X - point.X), 2) + Math.Pow((point1.Y - point.Y), 2));
            return true;
        }
        

    }
    class InputCase
    {
        public InputCase(int rowCount, int columnCount, int d, int unitHeight, int unitWidth)
        {
            m_Units = new Dictionary<int, Dictionary<int, Unit>>();
            RowCount = rowCount;
            ColumnCount = columnCount;
            D = d;
            UnitHeight = unitHeight;
            UnitWidth = unitWidth;
            for (int i = 0; i < columnCount; ++i)
            {

                Dictionary<int, Unit> unit = m_Units[i] = new Dictionary<int, Unit>();
                for (int j = 0; j < rowCount; ++j)
                    unit[j] = new Unit(i, j, UnitType.Empty);
            }
        }
        public int RowCount;
        public int ColumnCount;
        public Unit ImUnit;
        public int UnitHeight;
        public int UnitWidth;
        public int D;

        private Dictionary<int, Dictionary<int, Unit>> m_Units;
        public void SetUnit(int x, int y, UnitType type)
        {
            m_Units[x][y].UType = type;
            if (type == UnitType.Im)
                ImUnit = m_Units[x][y];
        }
        public Unit GetUnit(int x, int y)
        {
            return m_Units[x][y];
        }
    }
    enum UnitType
    {
        Im,
        Empty,
        Mirror
    }
    struct Point
    {
        public Point(double x, double y)
        {
            X = x;
            Y = y;
        }
        public double X;
        public double Y;
    }
    enum MirrorType
    {
        None,
        Up,
        Down,
        Left,
        Right,
        UpLeft,
        UpRight,
        DownLeft,
        DownRight,
        LeftUp,
        LeftDown,
        RightUp,
        RightDown,

        OppositeCorner,
        FullCorner,
    }
    enum BarrierType
    {
        Edge,
        Corner
    }
    class Unit
    {
        public Unit(int xPosition, int yPosition, UnitType uType)
        {
            XPosition = xPosition;
            YPosition = yPosition;
            UType = uType;
        }
        public UnitType UType;
        public int XPosition;
        public int YPosition;
    }
}
