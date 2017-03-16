using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = new Input();
            var output = new Output();
            /*
            input.loadString(
@"4
4 11111
1 09
5 110011
0 1");*/
            input.loadFile(@"C:\Users\talal\Downloads\A-large.in");
            output.setSaveFile(@"C:\Users\talal\Downloads\0.out");

            var testCaseCount = input.readInt();
            for (int testCaseIdx = 0; testCaseIdx < testCaseCount; testCaseIdx++)
            {
                var data = input.readStrArr();
                var maxShynessLevel = Convert.ToInt32(data[0]);
                var shynessLevelMemberCountList = data[1];//.ToArray();

                int membersCount = 0;
                int friendsCount = 0;
                for (int shynessLevel = 0; shynessLevel < maxShynessLevel + 1; shynessLevel++)
                {
                    var addFriends = 0;
                    if (membersCount < shynessLevel)
                    {
                        addFriends = shynessLevel - membersCount;
                    }

                    var levelCount = Convert.ToInt32(shynessLevelMemberCountList.Substring(shynessLevel, 1));
                    membersCount += levelCount + addFriends;
                    friendsCount += addFriends;
                }

                output.writeLine(friendsCount.ToString());
            }
            output.end();
        }
    }
}
