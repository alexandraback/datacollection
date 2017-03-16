#region Usings

using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

#endregion

class D_DeceitfulWar
{
    static void Main()
    {
        var T = Read<int>();
        for (int t = 1; t <= T; t++)
        {
            var N = Read<int>();
            var Naomi = ReadArray<double>(N);
            var Ken = ReadArray<double>(N);

            Array.Sort(Naomi);
            Array.Sort(Ken);

            int i, j;

            for (i = 0, j = 0; i < N; i++)
            {
                if (Naomi[i] > Ken[j])
                    j++;
            }
            int deceitfulNaomi = j;
            
            for (i = 0, j = 0; j < N; j++)
            {
                if (Naomi[i] < Ken[j])
                    i++;
            }
            int warNaomi = N - i;

            Console.WriteLine("Case #{0}: {1} {2}", t, deceitfulNaomi, warNaomi);
        }
    }

    #region Helpers

    static readonly char[] separator = { ' ', '\t' };

    static T Parse<T>(string text) where T : struct
    {
        switch (Type.GetTypeCode(typeof(T)))
        {
            case TypeCode.Single: return (T)(ValueType)Single.Parse(text);
            case TypeCode.Double: return (T)(ValueType)Double.Parse(text);
            case TypeCode.Decimal: return (T)(ValueType)Decimal.Parse(text);

            case TypeCode.SByte: return (T)(ValueType)SByte.Parse(text);
            case TypeCode.Int16: return (T)(ValueType)Int16.Parse(text);
            case TypeCode.Int32: return (T)(ValueType)Int32.Parse(text);
            case TypeCode.Int64: return (T)(ValueType)Int64.Parse(text);

            case TypeCode.Byte: return (T)(ValueType)Byte.Parse(text);
            case TypeCode.UInt16: return (T)(ValueType)UInt16.Parse(text);
            case TypeCode.UInt32: return (T)(ValueType)UInt32.Parse(text);
            case TypeCode.UInt64: return (T)(ValueType)UInt64.Parse(text);

            default: throw new ArgumentException("Could not parse " + typeof(T).Name + ": " + text);
        }
    }

    static T Read<T>() where T : struct
    {
        return Parse<T>(Console.ReadLine());
    }

    static T[] ReadArray<T>(int? expectedCount = null) where T : struct
    {
        var line = Console.ReadLine();
        var parts = line.Split(separator, StringSplitOptions.RemoveEmptyEntries);
        if (expectedCount != null && expectedCount != parts.Length)
            throw new ArgumentException("Expected exactly " + expectedCount + " items in line: " + line);
        var result = new T[parts.Length];
        for (int i = 0; i < parts.Length; i++)
            result[i] = Parse<T>(parts[i]);
        return result;
    }

    static T[,] ReadMatrix<T>(int rows, int columns) where T : struct
    {
        var result = new T[rows, columns];
        for (int i = 0; i < rows; i++)
        {
            var row = ReadArray<T>(columns);
            for (int j = 0; j < columns; j++)
                result[i, j] = row[j];
        }
        return result;
    }

    static void Read<T>(out T item) where T : struct
    {
        item = Read<T>();
    }

    static void Read<T>(out T item0, out T item1) where T : struct
    {
        var items = ReadArray<T>(2);
        item0 = items[0];
        item1 = items[1];
    }

    static void Read<T>(out T item0, out T item1, out T item2) where T : struct
    {
        var items = ReadArray<T>(3);
        item0 = items[0];
        item1 = items[1];
        item2 = items[2];
    }

    static void Read<T>(out T item0, out T item1, out T item2, out T item3) where T : struct
    {
        var items = ReadArray<T>(4);
        item0 = items[0];
        item1 = items[1];
        item2 = items[2];
        item3 = items[3];
    }

    static void Read<T>(out T item0, out T item1, out T item2, out T item3, out T item4) where T : struct
    {
        var items = ReadArray<T>(5);
        item0 = items[0];
        item1 = items[1];
        item2 = items[2];
        item3 = items[3];
        item4 = items[4];
    }

    static void Read<T>(out T item0, out T item1, out T item2, out T item3, out T item4, out T item5) where T : struct
    {
        var items = ReadArray<T>(6);
        item0 = items[0];
        item1 = items[1];
        item2 = items[2];
        item3 = items[3];
        item4 = items[4];
        item5 = items[5];
    }

    static void Read<T>(out T item0, out T item1, out T item2, out T item3, out T item4, out T item5, out T item6) where T : struct
    {
        var items = ReadArray<T>(7);
        item0 = items[0];
        item1 = items[1];
        item2 = items[2];
        item3 = items[3];
        item4 = items[4];
        item5 = items[5];
        item6 = items[6];
    }

    static void Read<T>(out T item0, out T item1, out T item2, out T item3, out T item4, out T item5, out T item6, out T item7) where T : struct
    {
        var items = ReadArray<T>(8);
        item0 = items[0];
        item1 = items[1];
        item2 = items[2];
        item3 = items[3];
        item4 = items[4];
        item5 = items[5];
        item6 = items[6];
        item7 = items[7];
    }

    #endregion
}
