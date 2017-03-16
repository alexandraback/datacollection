using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1C
{
    class Pogo
    {
        public static String GetMovements(int x, int y)
        {
            int actX = 0, actY = 0;
            int distanceX = Math.Abs(x), distanceY = Math.Abs(y);
            bool changeX = x < 0;
            bool changeY = y < 0;

            int actualIncrement = 1;

            StringBuilder result = new StringBuilder();

            int fixedActX = 0;
            int fixedActY = 0;
            while ( fixedActX != x || fixedActY != y )
            {
                char move = GetMove(actualIncrement, actX, actY, distanceX, distanceY);
                switch (move)
                {
                    case 'N':
                        actY += actualIncrement;
                        if (changeY)
                            result.Append('S');
                        else
                            result.Append('N');
                        break;

                    case 'S':
                        actY -= actualIncrement;
                        if (changeY)
                            result.Append('N');
                        else
                            result.Append('S');
                        break;

                    case 'E':
                        actX += actualIncrement;
                        if (changeX)
                            result.Append('W');
                        else
                            result.Append('E');
                        break;

                    case 'W':
                        actX -= actualIncrement;
                        if (changeX)
                            result.Append('E');
                        else
                            result.Append('W');
                        break;
                }
                ++actualIncrement;
                distanceX = Math.Abs(x) - actX;
                distanceY = Math.Abs(y) - actY;

                fixedActX = changeX ? -actX : actX;
                fixedActY = changeY ? -actY : actY;
            }

            return result.ToString();
        }

        public static char GetMove(int actualIncrement, int actX, int actY, int distanceX, int distanceY)
        {
            if (actualIncrement == distanceX)
                return 'E';

            if (actualIncrement == distanceY)
                return 'N';

            if (actualIncrement == -distanceX)
                return 'W';

            if (actualIncrement == -distanceY)
                return 'S';


            //Check what direction I have to take
            int newDistanceX = Math.Abs(Math.Abs(distanceX) - actualIncrement);
            int newDistanceY = Math.Abs(Math.Abs(distanceY) - actualIncrement);

            if (newDistanceX < newDistanceY)
            {
                //E or W
                if (Math.Abs(newDistanceX) < Math.Abs(distanceX))
                {
                    if (distanceX > 0)
                        return 'E';

                    return 'W';
                }
                else
                {
                    if (distanceX > 0)
                        return 'W';

                    return 'E';
                }
            }
            else
            {
                if (Math.Abs(newDistanceY) <= Math.Abs(distanceY))
                {
                    if (distanceY > 0)
                        return 'N';

                    return 'S';
                }
                else
                {
                    if (distanceY > 0)
                        return 'S';

                    return 'N';
                }
            }

            return 'S';

        }
    }
}
