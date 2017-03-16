using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test {

    public class C2DArray<T> {
        protected C2DCell<T>[][] mArray;
        protected int mRows;
        protected int mCols;

        public C2DCell<T>[][] Array {
            get {
                return mArray;
            }
        }
        public int Rows {
            get {
                return mRows;
            }
        }
        public int Cols {
            get {
                return mCols;
            }
        }

        public C2DArray(int r, int c) {
            if (r < 1)
                r = 1;
            if (c < 1)
                c = 1;

            mRows = r;
            mCols = c;

            mArray = new C2DCell<T>[r][];
            for (int i = 0; i < r; i++) {
                mArray[i] = new C2DCell<T>[c];
                for (int j = 0; j < c; j++) {
                    mArray[i][j] = new C2DCell<T>(this, i, j);
                }
            }
        }

        public void Swap(int i1, int j1, int i2, int j2) {
            T temp = Array[i1][j1].Val;
            Array[i1][j1].Val = Array[i2][j2].Val;
            Array[i2][j2].Val = temp;
        }
    }


    public class C2DCell<T> {
        protected C2DArray<T> mArray;
        protected int mRow;
        protected int mCol;
        protected T mVal;

        public T Val {
            get {
                return mVal;
            }
            set {
                mVal = value;
            }
        }
        public int Row {
            get {
                return mRow;
            }
            set {
                mRow = value;
            }
        }
        public int Col {
            get {
                return mCol;
            }
            set {
                mCol = value;
            }
        }
        public C2DCell<T> North {
            get {
                if (mArray == null)
                    return null;
                if (mRow == 0)
                    return null;

                return mArray.Array[mRow - 1][mCol];
            }
        }
        public bool ExistNorth {
            get {
                if (North == null)
                    return false;
                return true;
            }
        }
        public C2DCell<T> South {
            get {
                if (mArray == null)
                    return null;
                if (mRow == mArray.Rows - 1)
                    return null;

                return mArray.Array[mRow + 1][mCol];
            }
        }
        public bool ExistSouth {
            get {
                if (South == null)
                    return false;
                return true;
            }
        }
        public C2DCell<T> West {
            get {
                if (mArray == null)
                    return null;
                if (mCol == 0)
                    return null;

                return mArray.Array[mRow][mCol - 1];
            }
        }
        public bool ExistWest {
            get {
                if (West == null)
                    return false;
                return true;
            }
        }
        public C2DCell<T> East {
            get {
                if (mArray == null)
                    return null;
                if (mCol == mArray.Cols - 1)
                    return null;

                return mArray.Array[mRow][mCol + 1];
            }
        }
        public bool ExistEast {
            get {
                if (East == null)
                    return false;
                return true;
            }
        }

        public C2DCell(int r, int c) {
            mRow = r;
            mCol = c;
        }

        public C2DCell(int r, int c, T v) {
            mRow = r;
            mCol = c;
            mVal = v;
        }

        public C2DCell(C2DArray<T> arr, int r, int c) {
            mArray = arr;
            mRow = r;
            mCol = c;
        }

        public C2DCell(C2DArray<T> arr, int r, int c, T v) {
            mArray = arr;
            mRow = r;
            mCol = c;
            mVal = v;
        }
    }
}
